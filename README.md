# Emulation Detection via Hostname Change

## Overview
This project implements a simple technique to detect if a program is running in an **emulation** or **sandbox environment** by checking whether the `hostname` can be dynamically changed.

### **Credits**
This technique was originally discovered by **Grzegorz Tworek** [@0gtweet](https://twitter.com/0gtweet), a security researcher known for his work on Windows internals.

## How It Works
- On a real Windows system, setting `_CLUSTER_NETWORK_NAME_` does **not** change the hostname.
- In some AV emulators or sandboxes, `hostname` is **hooked**, and the value changes.
- If the hostname changes, the system is likely **real**.
- If the hostname stays the same, an **emulated environment** might be detected.

## Compilation
### **Using Microsoft Visual C++ (MSVC)**
Run the following command in the project directory:
```sh
cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tc src/emulation_detect.c /link /OUT:detect.exe /SUBSYSTEM:CONSOLE /MACHINE:x64
