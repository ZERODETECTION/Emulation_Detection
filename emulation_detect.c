#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 256

void get_hostname(char *buffer, DWORD size) {
    DWORD len = size;
    if (!GetComputerNameA(buffer, &len)) {
        printf("Error retrieving hostname!\n");
    }
}

int main() {
    char original_hostname[BUFFER_SIZE] = {0};
    char new_hostname[BUFFER_SIZE] = {0};

    // Get the original hostname
    get_hostname(original_hostname, BUFFER_SIZE);
    printf("Original Hostname: %s\n", original_hostname);

    // Set the environment variable (some AV emulators may hook this)
    SetEnvironmentVariableA("_CLUSTER_NETWORK_NAME_", "FAKE");

    // Retrieve the hostname again
    get_hostname(new_hostname, BUFFER_SIZE);
    printf("New Hostname: %s\n", new_hostname);

    // Check if the hostname has changed
    if (strcmp(original_hostname, new_hostname) == 0) {
        printf("[!] Detected possible emulation or sandbox environment!\n");
        return 1;
    } else {
        printf("[+] Running in a normal environment.\n");
    }

    return 0;
}
