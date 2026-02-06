# JboDB Database (C)

A simple key-value database implemented in C.

This project is primarily a learning exercise to understand how real database storage engines work, starting from an append-only log and evolving toward an LSM-style design (memtable + flush + SSTables + compaction).

---

## Goals

- Build a durable key/value store from scratch
- Learn how WAL (write-ahead logging), memtables, flushing, and compaction work
- Keep the project small and incremental (avoid premature abstraction)

---

## Roadmap / Phases

### Phase 0 — Project Setup
**Goal:** Have a runnable program and a basic command interface.

- [ ] Basic executable that runs without crashing
- [ ] Accept simple commands (CLI args or stdin):
  - `PUT key value`
  - `GET key`
  - `DEL key`
- [ ] Print clear responses (`OK`, `NOT_FOUND`, etc.)
- [ ] Handle invalid input gracefully

---

### Phase 1 — Append-Only Log (WAL)
**Goal:** Writes are durable.

- [ ] Define a log record format:
  - `PUT,key,value`
  - `DEL,key`
- [ ] Append all writes to a log file
- [ ] Log is append-only (never edited)
- [ ] Ensure log append succeeds before returning success

---

### Phase 2 — Memtable (In-Memory Hash Table)
**Goal:** Reads and writes operate on an in-memory structure.

- [ ] Implement an in-memory hash table (memtable)
- [ ] Store latest values per key
- [ ] Support tombstones for deletes (`DEL`)
- [ ] `GET` reads from memtable
- [ ] `PUT/DEL` update memtable

---

### Phase 3 — Correct Write Ordering
**Goal:** Crash safety.

For `PUT` and `DEL`:
- [ ] Append record to WAL first
- [ ] Only update memtable after WAL append succeeds

This ensures restart recovery is always correct.

---

### Phase 4 — Startup Recovery
**Goal:** Database state survives restarts.

- [ ] On startup, replay the WAL into an empty memtable
- [ ] Ensure last-write-wins behavior is correct
- [ ] Deletes persist correctly across restart

---

### Phase 5 — Memtable Size Tracking
**Goal:** Prepare for flushing.

- [ ] Track memtable size (entry count or approximate bytes)
- [ ] Define a maximum memtable size threshold
- [ ] When exceeded, mark memtable for flushing

---

### Phase 6 — Flush Memtable to Disk (SSTable v1)
**Goal:** Persist database state beyond the WAL.

- [ ] Freeze current memtable when full
- [ ] Write memtable contents to a disk table file (SSTable)
- [ ] Create a fresh empty memtable for new writes
- [ ] Disk table file is immutable once written

---

### Phase 7 — Read From Disk Tables
**Goal:** Reads work even if the key is not in memory.

- [ ] If key not found in memtable, search disk table files
- [ ] Search newest tables first
- [ ] Tombstones on disk must correctly hide older values

---

### Phase 8 — WAL Rotation / Checkpointing
**Goal:** Avoid replaying the entire history forever.

- [ ] After a successful flush, WAL entries before that flush are no longer needed
- [ ] Implement WAL truncation or
