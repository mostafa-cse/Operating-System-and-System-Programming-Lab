# Operating System and System Programming Lab
Here are detailed descriptions for each of the four major algorithm categories you’ve listed:

---

## 1. Scheduling Algorithms

These decide which ready process will next use the CPU.

### 1.1 First‑Come, First‑Served (FCFS)

* **Mechanism**: Enqueue processes in arrival order; dequeue the head for execution.
* **Pros**: Very simple; no starvation.
* **Cons**: “Convoy effect” (short jobs wait behind long ones), poor average turnaround.

### 1.2 Shortest Job First (SJF) / Shortest Remaining Time First (SRTF)

* **Mechanism**: Pick the process with the smallest (estimated) CPU burst.

  * **SJF** is non‑preemptive; once a job starts, it runs to completion.
  * **SRTF** is preemptive; a newly arriving shorter job can preempt the current one.
* **Pros**: Minimizes average waiting time.
* **Cons**: Needs accurate burst estimates; long jobs may starve under heavy short‑job load.

### 1.3 Round‑Robin (RR)

* **Mechanism**: Each process gets a fixed time quantum; if it doesn’t finish, it goes to the back of the ready queue.
* **Pros**: Time‑sharing; good response for interactive systems; no starvation.
* **Cons**: Too small a quantum ⇒ high context‑switch overhead; too large ⇒ degrades toward FCFS.

### 1.4 Priority Scheduling

* **Mechanism**: Each process has a static or dynamic priority; the scheduler always picks the highest‑priority ready process.
* **Pros**: Critical or real‑time tasks run promptly.
* **Cons**: Low‑priority tasks can starve; needs aging or priority‑boost schemes to prevent it.

### 1.5 Multilevel Queue & Feedback Queues

* **Multilevel Queue**: Separate queues for, e.g., interactive vs. batch jobs; each queue can have its own scheduling discipline.
* **Multilevel Feedback Queue**: Processes can move between queues based on their CPU/memory behavior (e.g., CPU‑bound vs. I/O‑bound).
* **Pros**: Tailors scheduling to different job classes.
* **Cons**: Complex to configure (number of queues, time quanta, promotion/demotion rules).

---

## 2. Page Replacement Algorithms

When RAM is full and a page fault occurs, these decide which page to evict.

### 2.1 First‑In, First‑Out (FIFO)

* **Mechanism**: Evict the oldest loaded page (maintain a queue of loaded pages).
* **Pros**: Extremely simple.
* **Cons**: Ignores how often or how recently a page is used; can evict hot pages.

### 2.2 Optimal (Belady’s)

* **Mechanism**: Evict the page whose next use is farthest in the future.
* **Pros**: Theoretical minimum page‑fault rate.
* **Cons**: Requires clairvoyance—used only as a benchmark.

### 2.3 Least Recently Used (LRU)

* **Mechanism**: Evict the page that hasn’t been used for the longest time.
* **Pros**: Good approximation to Optimal in practice.
* **Cons**: Needs hardware support (reference bits) or software overhead (timestamps or stacks).

### 2.4 Clock (Second‑Chance)

* **Mechanism**: Pages are in a circular “clock” list with a reference bit; the hand advances, clearing bits on first pass and evicting on second.
* **Pros**: Near‑LRU performance at much lower bookkeeping cost.
* **Cons**: Still requires per‑page reference tracking and hand management.

---

## 4. Memory Allocation Algorithms

These place arriving processes into free memory segments (or free segments into holes).

### 4.1 First Fit

* **Mechanism**: Scan from the beginning of memory; place the process in the first hole that’s large enough.
* **Pros**: Fast allocation (stops at first fit).
* **Cons**: Tends to produce many small holes near the front → external fragmentation.

### 4.2 Best Fit

* **Mechanism**: Scan all holes; choose the smallest hole that is still ≥ process size.
* **Pros**: Minimizes leftover hole size.
* **Cons**: Slow (must scan all holes); creates lots of tiny unusable fragments.

### 4.3 Worst Fit

* **Mechanism**: Place the process in the largest available hole.
* **Pros**: Leaves large leftover holes (in theory, for future big processes).
* **Cons**: Often performs poorly—still fragments, and biggest holes get carved up inefficiently.

---

## 5. Deadlock Handling Algorithms

Strategies to ensure that competing processes sharing resources do not end up in a circular wait.

### 5.1 Deadlock Prevention

* **Mechanism**: Design the system so that at least one of the four Coffman conditions (mutual exclusion, hold‑and‑wait, no preemption, circular wait) can never occur.
* **Example**: Require processes to request all resources up‑front (eliminates hold‑and‑wait).
* **Pros**: No deadlocks ever.
* **Cons**: Very conservative—lowers utilization; can be complex to enforce.

### 5.2 Deadlock Avoidance (Banker’s Algorithm)

* **Mechanism**: Before granting a request, the OS simulates resource allocation to check if the system would remain in a “safe state” (i.e., a sequence exists where every process can finish).
* **Pros**: More concurrent than strict prevention; no deadlocks.
* **Cons**: Requires advance knowledge of each process’s maximum resource needs; overhead of safety checks.

### 5.3 Deadlock Detection & Recovery

* **Detection**: Periodically examine a resource‑allocation graph or use a detection algorithm (like a variant of the Banker’s safety check) to find cycles.
* **Recovery**: Once deadlock is detected, break it by aborting or rolling back one or more involved processes, or by preempting resources.
* **Pros**: Freer resource usage under normal operations.
* **Cons**: Detection adds overhead; recovery may require killing processes or complex checkpointing.

---
<div align="center">
  <img width="600" height="273" alt="image" src="https://github.com/user-attachments/assets/4e9d34e6-c9f9-452a-b944-3a93db8bfdf6" />
</div>

