Tetris (Windows Console)

![Tetris](https://github.com/frogkim/pictures/blob/main/tetris.png)https://github.com/frogkim/pictures/blob/main/tetris.png](https://github.com/frogkim/pictures/blob/main/tetris.png)https://github.com/frogkim/pictures/blob/main/tetris.png)

This is a tetris, a console game using only Windows API. I excluded to use conio intentionally. There is two reasons about it. First, I want to make a program without 3rd party's library as possible. The library is comportable, but we cannot know inside it. When the document they provide is unkind, it is terrible when debugging. Also, if a program depends on too many other's library, maintaining a program be harder. Cunio is old program and Visual Studio provides it with SDK, but I want to use Windows API as possible. The other reason is that I want to follow recent trend. Some document about console by MS are provided. It looks like MS tried to make a change in console API. I just want to learn about it.

This program has a big problem. It is a tiny software, but I take high CPU usage. The reason is **busy wait**. When it wait for user's input, it loops in a block. Just looping a block needs also needs resources. It inspired me to consider **event driven** design.
