kmain:
 ; Greet the user!
 mov esi, hello
 call kputs

 ; Testing 1 2 3 4 5
 mov esi, try_kbd
 call kputs

.kbd_try_loop:
 call read_kbd
 loop .kbd_try_loop

hello: db "Hello world!!!", 0
trykdb: db "You may try the keyboard driver here. It is a work in progress, and sometimes doesn't work.", 0
