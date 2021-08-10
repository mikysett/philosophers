# Philosophers - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

## philo directory (threads and mutex)

- N philosophers (threads) sitting at a circular table
- N forks (mutex), one at the right of every philosopher
- 2 forks necessary to eat
- Run with `./philo [number of philosophers] [time to die] [time to eat] [time to sleep] [optional: number of meals before to stop]`

## philo_bonus directory (semaphores and processes) - STILL WORK IN PROGRESS
- Same rules as philo
- All the forks are in the middle of the table (represented by a semaphore)
- Now each philosopher is a process

### Notes
- `usleep` function introduced a delay that make philosophers die when the time for eating is 10ms (for exampe `./philo 4 410 200 200`, this gap was not noticeable on my Linux machine with i7 8th gen processor). To fix it I created a custom sleep function.
- Be careful of odd philosopher number (ex: `./philo 5 800 200 200`), this introduce odd forks and add priorities issues that can land in philosophers dying when they are not supposed to. This issue has been fixed here by adding a small mandatory time of thinking after sleep (this naturally gives philosophers thinking since more time priority over the just-released forks without breaking encapsulation).
- Right now the printer kill everybody trying to print if somebody dies. To have a perfect incapsulation it would be nice to try creating threads with detach (instead of join) that will operate on two shared variables (one boolean for `somebody died` and one array of booleans for `eat enough meals`). Then the main thread will be able to check those variables and wait until they become thrue, switching the responsability to orchestrate the program exit from the printer to the main thread.