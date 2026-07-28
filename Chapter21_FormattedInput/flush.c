#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("You'll see this immediately.\n" "Now count to 5 slowly.\n");
    // Both lines end with \n, and \n tells the buffer
    // "send everything now" — so this prints right away.

    printf("Then this will appear ... ");
    // No \n at the end here! So this text just sits
    // quietly in memory (the buffer) — nothing shows
    // on screen yet, even though we "called printf."

    sleep(5);
    // Program just pauses for 5 seconds.
    // The text above is STILL waiting in the buffer,
    // invisible, doing nothing.

    printf("when the buffer is finally flushed.\n");
    // This \n finally says "send everything now" —
    // and it sends BOTH this text AND the previous
    // waiting text together, all at once.

    return 0;
}
