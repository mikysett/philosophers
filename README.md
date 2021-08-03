# Philosophers - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

## philo directory (threads and mutex)

- N philosophers (threads) sitting at a circular table
- N forks (mutex), one at the right of every philosopher
- 2 forks necessary to eat
- Run with `./philo [time to die] [time to eat] [time to sleep] [optional: number of meals before to stop`

## philo_bonus directory (semaphores and processes) - STILL WORK IN PROGRESS
- Same rules as philo
- All the forks are in the middle of the table (represented by a semaphore)
- Now each philosopher is a process