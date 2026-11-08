# Green Efficiency Analysis

## Measurement Methodology

I compiled all the programs with the required flags (`-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`) and ran everything on the same machine. To measure time I used `clock()` from `time.h` and divided the difference by `CLOCKS_PER_SEC` to get seconds.

I ran each program 3 times in a row. For the comparison task I took the average of the 3 runs for each algorithm and then divided the naive average by the single-pass average to see how many times slower it is.

For the instrumentation lab, I put a `start = clock()` before each function call and an `end = clock()` right after it, so each phase is measured alone. For TOTAL I used separate variables that start before the first phase and stop after the last one. This way TOTAL always covers all the phases, so it can't be smaller than any of them. I kept the printf lines outside the timing.

## Observed Performance Differences

For the baseline loop (100,000,000 iterations) I got 0.228322, 0.232213 and 0.230165 seconds. The times were close but not exactly the same.

In the comparison program the naive algorithm took 2.754894, 2.756685 and 2.757168 seconds, so the average is about 2.756249 seconds. The single-pass algorithm took 0.000106, 0.000109 and 0.000105 seconds, average about 0.000107 seconds. That means the naive one is around 25,840 times slower.

I think this makes sense when looking at the code. The naive version goes back to the start of the array for every element, so the inner loop runs about 1.25 billion times (50,000 × 50,001 / 2). The single-pass version only goes through the array once, which is 50,000 times. So the difference is mostly because of how many operations each one does, not because one operation is slower than the other.

In the instrumentation lab I got TOTAL 0.000745 seconds, BUILD_DATA 0.000283, PROCESS 0.000322 and REDUCE 0.000135 seconds. PROCESS was the slowest phase (about 43% of the total) and REDUCE was the fastest. The three phases add up to 0.000740, which is a little less than TOTAL. I think the small difference comes from the extra clock() calls between the phases.

## Relation Between Runtime and Energy Consumption

We didn't measure real power in this project, so I used runtime as a proxy. If the CPU is working for a longer time, it uses more energy. The naive algorithm kept the CPU busy for about 2.75 seconds, while the single-pass one finished the same job in about 0.0001 seconds. If we assume the CPU uses about the same power in both cases, the naive version would use a lot more energy (roughly 25,000 times more) for the same input.

## Limitations of the Experiment

- The single-pass times are very small (around 0.0001 seconds), which is close to what `clock()` can measure accurately. A tiny change like 0.000004 seconds is already about 4% of the value, so the 25,840 number is not exact.
- I only did 3 runs for each program, which is not a lot.
- I ran the tests in a shared virtual machine, so other things running at the same time could affect the results.
- We didn't measure watts, so the energy part is based on an assumption and not a real measurement.

## Practical Engineering Takeaway

The biggest thing I learned is that the choice of algorithm matters much more than small details in the code. Going from a nested loop to a single loop made the program thousands of times faster in my tests, and faster usually means less energy. Also, it is better to measure than to guess, and to run the program more than once because the results change a little each time. Measuring each phase separately also helps to see which part actually takes the most time before trying to optimize anything.
