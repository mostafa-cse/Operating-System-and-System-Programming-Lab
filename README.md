# Operating System and System Programming Lab
---
## 1. Scheduling Algorithms

Decide which ready process gets the CPU next.

| Algorithm                                       | How It Works                                                                                        | Advantages                                                                                   | Disadvantages                                                                                    |
| ----------------------------------------------- | --------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| **1.1 First-Come, First-Served (FCFS)**         | Processes are queued in arrival order; the scheduler picks from the head of the queue.              | • Very simple to implement<br>• Fair in terms of arrival sequence                            | • “Convoy effect”: short tasks wait behind long ones<br>• High average turnaround time           |
| **1.2 Shortest Job First (SJF)**                | Always selects the process with the smallest predicted CPU burst.                                   | • Minimizes average waiting time                                                             | • Requires accurate burst‐time estimates<br>• Longer jobs may starve if short jobs keep arriving |
| **1.3 Round-Robin (RR)**                        | Gives each process a time slice (quantum). On expiry, it’s preempted and moved to the queue’s tail. | • Good responsiveness for interactive tasks<br>• Prevents starvation (with a proper quantum) | • Too‐small quantum → high context‐switch overhead<br>• Too‐large quantum → degrades to FCFS     |
| **1.4 Priority Scheduling**                     | Each process has a priority; the highest‐priority ready process runs next.                          | • Critical or real-time tasks run promptly                                                   | • Low-priority starvation unless you implement aging<br>• Selecting priorities can be subjective |
| **1.5 Multilevel Queue (MLQ) & Feedback Queue** | Multiple ready queues, each with its own scheduling policy.                                         |                                                                                              |                                                                                                  |

* **MLQ**: processes are fixed to one queue.
* **Multilevel Feedback**: processes may move between queues based on their CPU/IO behavior. | • Can tailor service to different job classes (e.g., interactive vs. batch)
  • Feedback allows dynamic adjustment | • Complex to configure: number of queues, time slices, promotion/demotion rules

---

## 2. Page Replacement Algorithms

When RAM is full, decide which page to evict to make room for a new page.

| Algorithm                          | How It Works                                                                   | Advantages                                | Disadvantages                                                                  |
| ---------------------------------- | ------------------------------------------------------------------------------ | ----------------------------------------- | ------------------------------------------------------------------------------ |
| **2.1 First-In, First-Out (FIFO)** | Evicts the page that has been in memory the longest (oldest arrival).          | • Extremely simple (use a queue)          | • Does not consider actual use → may evict hot pages (“Belady’s anomaly”)      |
| **2.2 Optimal (Belady’s)**         | Evicts the page whose next use is farthest in the future.                      | • Theoretically minimal page-fault rate   | • Impossible in practice (requires future knowledge); only used for comparison |
| **2.3 Least Recently Used (LRU)**  | Evicts the page that has not been referenced for the longest time in the past. | • Good practical approximation of Optimal | • Needs hardware/support (counters or stack) → overhead                        |
| **2.4 Clock (Second-Chance)**      | Pages are arranged in a circular list with a “use” bit.                        |                                           |                                                                                |

1. Check the current page’s use bit.
2. If 0 → evict. If 1 → clear bit, advance hand, repeat. | • Approximates LRU at much lower cost | • Hand may cycle multiple times if many pages have use bit = 1 |

---

## 3. Memory Allocation Algorithms

Manage how free memory blocks are assigned to processes requesting various sizes.

| Algorithm         | How It Works                                                                      | Advantages                                | Disadvantages                                          |
| ----------------- | --------------------------------------------------------------------------------- | ----------------------------------------- | ------------------------------------------------------ |
| **3.1 First Fit** | Scan the free‐block list from the start; choose the first block ≥ requested size. | • Fast allocation time                    | • External fragmentation near the front of memory      |
| **3.2 Best Fit**  | Scan all free blocks; choose the smallest block ≥ requested size.                 | • Minimizes leftover space per allocation | • Slow search; creates many small unusable fragments   |
| **3.3 Worst Fit** | Choose the largest available block; split off the requested portion.              | • Tends to leave medium-sized blocks free | • Often performs worse than First/Best Fit in practice |

---

## 4. Deadlock Handling Algorithms

Ensure processes don’t get stuck waiting forever for resources.

| Algorithm                                       | How It Works                                                                                                                                                                | Advantages                                | Disadvantages                                                                                         |
| ----------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| **4.1 Deadlock Prevention**                     | Proactively restricts how resources are requested so at least one of the Coffman conditions (mutual exclusion, hold-and-wait, no preemption, circular wait) can never hold. | • Deadlock can never occur                | • Very conservative resource usage<br>• Can reduce concurrency dramatically                           |
| **4.2 Deadlock Avoidance (Banker’s Algorithm)** | Before granting a request, simulates allocation to ensure the system remains in a “safe state” (i.e., there exists a sequence that can satisfy all maximum demands).        | • Allows more concurrency than prevention | • Requires knowing each process’s maximum future demands<br>• Computational overhead for each request |
| **4.3 Deadlock Detection & Recovery**           |                                                                                                                                                                             |                                           |                                                                                                       |

1. **Detection**: Periodically build a resource-allocation graph or run an algorithm to find cycles.
2. **Recovery**: Break the cycle by aborting or rolling back one or more processes, or forcibly preempting resources. | • No upfront restrictions on resource requests | • Detection adds runtime overhead<br>• Recovery can be disruptive (process termination or complex rollback) |

---

## ⏱️ 5. Shot Time Preparation

| Topic                     | Resource Link                                                                                      |
|--------------------------|----------------------------------------------------------------------------------------------------|
| For On-spot Interview    | [Lecture Notes (Northeastern University)](https://www.ccs.neu.edu/home/lieber/com3336/f99/lectures/l1/l1.one.pdf) |
| For Brief Review         | [GeeksforGeeks - Operating Systems](https://www.geeksforgeeks.org/operating-systems/operating-systems)          |


---
<div align="center">
  <img width="600" height="273" alt="image" src="https://github.com/user-attachments/assets/4e9d34e6-c9f9-452a-b944-3a93db8bfdf6" />
</div>

