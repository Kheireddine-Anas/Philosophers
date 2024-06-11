# Philosophers Simulation - README

## Overview

This project simulates the classic "Dining Philosophers Problem" using threads and mutexes to manage synchronization. Philosophers alternately eat, think, and sleep while sharing a limited number of forks. The goal is to ensure that no philosopher starves, avoiding deadlocks and race conditions.

## Files
- **philosophers.h**: Header file containing declarations for functions, structs, and macros.
- **philo.c**: Contains the main function, initialization, and starting the simulation.
- **utils.c**: Utility functions like ft_atoi, ft_usleep, and printing.
- **utils1.c**: Additional utility functions and core simulation logic.

## Compilation

To compile the project, use the provided Makefile:

```bash
make
```

This will produce an executable named philo.

## Usage

Run the simulation with the following command:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- **number_of_philosophers**: Number of philosophers and forks.
- **time_to_die**: Time (in milliseconds) a philosopher can go without eating before dying.
- **time_to_eat**: Time (in milliseconds) it takes for a philosopher to eat.
- **time_to_sleep**: Time (in milliseconds) a philosopher spends sleeping.
- **[number_of_times_each_philosopher_must_eat]** (optional): If provided, the simulation ends when all philosophers have eaten at least

```bash
./philo 5 800 200 200
```

This command runs the simulation with 5 philosophers, where each philosopher will die if they don't eat within 800ms, takes 200ms to eat, and 200ms to sleep.

## Logging

State changes are logged with timestamps and philosopher numbers:

- ***timestamp_in_ms X has taken a fork***
- ***timestamp_in_ms X is eating***
- ***timestamp_in_ms X is sleeping***
- ***timestamp_in_ms X is thinking***
- ***timestamp_in_ms X died***

## Key Functions

**Initialization**

- ***init_philos***: Initializes philosopher parameters and allocates memory for tracking their states and mutexes.

**Simulation**

- ***repetition***: Main function for each philosopher thread, managing their life cycle (thinking, eating, sleeping).
eating_cycle: Handles the eating phase, including taking forks, eating, and updating last meal time.

- ***ending_cycle***: Monitors the simulation, checking for starvation and whether all philosophers have eaten the required number of times.

**Utilities**

- ***ft_atoi***: Converts a string to an integer.

- ***ft_usleep***: Custom sleep function to check for life state during sleep intervals.

- ***ft_printer***: Logs state changes to the console with timestamps.

## Thread Management

- ***thread_make***: Initializes and starts threads for each philosopher.

- ***thread_join***: Joins threads to ensure proper synchronization and cleanup.

## Clean Up

- ***ft_destroy***: Frees allocated memory and destroys mutexes.

## Rules and Constraints

- Global variables are forbidden.

- Use mutexes to protect shared resources (forks).

- Ensure no data races occur.

- State messages must be distinct and not mixed up.

- Death of a philosopher must be logged within 10ms of actual death.

- The program should handle various argument checks and constraints robustly.

## Conclusion

This project effectively demonstrates thread synchronization and mutex management by simulating the dining philosophers problem. Proper handling of philosopher states, fork usage, and starvation prevention are critical to ensuring the simulation runs correctly and efficiently.