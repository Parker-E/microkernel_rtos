# Microkernel RTOS for ESP32

## Overview
- **Features:** Task scheduling, IPC, synchronization (mutex, semaphore, event flags)
- **Components:** kernel, tasks, synchronization, IPC

## Setup
1. **Install ESP-IDF:**
2. **Clone repo into /esp-idf/**
    - Follow [ESP-IDF Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)
3. **Build & Flash**
   ```sh
   idf.py build
   idf.py flash
   idf.py monitor

## File Structure
- **main.c:** Entry point
- **kernel.c/h:** Kernel functions
- **task.c/h:** Task management
- **semaphore.c/h:** Semaphore
- **mutex.c/h:** Mutex
- **event_flags.c/h:** Event flags
- **ipc.c/h:** Interprocess communication

## Usage
1. **Define tasks in `main.c`**
2. **Create tasks -> `create_task`**
3. **Start kernel -> `kernel_start`**

## Test Scenarios
- **Task 1:** Set event, signal semaphore, send message through ipc
- **Task 2:** Wait event, lock/unlock mutex, wait semaphore
- **Task 3:** Periodic print