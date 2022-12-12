# PP Library

Basically, I wanted an easy way to have PP calculation in my programs.
Turns out, PP calculation is massively complicated.

This library aims to expose the core of difficulty and PP calculation in C++ and C code.

# Stolen Code

PP Calculation was totally yoinked from: https://github.com/ppy/osu-performance   
Adapted to suit a library-style compilation and use.

Difficulty Calculation _will be_ transpiled from: https://github.com/ppy/osu-difficulty-calculator   
I gave up. Sorry.... might come back to this for fun some day, but very improbable.

The PP calculation is working, althought it's clunky to use since it hasn't been fully worked on.

If you for some god-forsaken reason need C bindings for difficulty and PP calculation, I will be working on
[crosu-pp](https://github.com/Minoxs/crosu-pp), which aims to do the same thing, but using an already build Rust core.

# Thanks

To ppy and the osu! team  
To @OMKelderman (developer of [SanDoku](https://github.com/omkelderman/SanDoku/tree/master/SanDoku)) for pointing me in the right direction
