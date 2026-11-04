# Lab9_System_Calls
**Must be running this in Linux.**

**to compile (in terminal)**: `make`

## Executable functions
### `info`
prints system information.
current time (ns), network name, OS name/release/version/hardware type, #cpus, physical/free memory(bytes)
to run: `./info`

### `pmod`
reduces the current process's priority by 10
sleeps for 1.837227638 seconds
to run: `./pmod`

### pinfo
prints information regarding the given process ID.
PID, priority, scheduling method
to run: `./pinfo` or `./pinfo decimalPID`

### finfo
prints file information.
file type, user permissions, owner (decimal), file size, time of last modification
to run: `./finfo file`
