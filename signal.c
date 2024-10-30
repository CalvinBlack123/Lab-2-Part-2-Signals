/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_called = 0; // Global variable to track if handler was called

void handler(int signum)
{
    // Signal handler for SIGALRM
    printf("Hello World!\n");
    handler_called = 1; // Set the flag when the handler is called
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler); // Register handler for SIGALRM

    while (1) {
        alarm(5); // Schedule a SIGALRM every 5 seconds
        while (!handler_called); // Busy wait for the signal to be delivered

        printf("Turing was right!\n"); // Print after handler is called
        handler_called = 0; // Reset the flag
    }

    return 0; // Never reached
}
