# DEF CON 30 Biohacking Village Badge Mod

This year's [Biohacking Village](https://www.villageb.io/) badge by [Badge Pirates](https://badgepirates.com/) was hands down one of the coolest badge designs I saw. It's modeled after the classic game Operation, with great artwork, and a slick laser cut insert to hold the implants in their respective body parts.

The copy I got to play with had some issues with the hit detection, with hearts in the health meter lighting up sporadically and in random order. This seemed like a debouncing issue, and I really wanted to fix it to do the awesome design justice.

Here's a demonstration of the badge in its initial state, and disassembly.


<video src="https://archive.org/download/dc30-biohacking-village-badge-mod/initial-stte.mp4 controls="controls" style="max-width:640px">


Inside I found a decade counter used to cycle through the health indicator LEDs, and an RC circuit and schmitt trigger for debouncing hits from the tweezers. I also saw an unpopulated spot for a buzzer, and suddenly really wanted a buzzer.


<a href="https://archive.org/download/dc30-biohacking-village-badge-mod/unmodified-board.jpg">
<img src="https://archive.org/download/dc30-biohacking-village-badge-mod/unmodified-board-640.jpg" width="640"/>
</a>


Initially I thought I'd add or modify the debouncing circuitry and be done with it, but once I got it opened up and reverse engineered I had some new ideas about how I wanted the health meter to behave, and I wanted that buzzer. So I decided to gut the board logic and replace it with a microcontroller. I desoldered everything except the LEDs and power components.


<a href="https://archive.org/download/dc30-biohacking-village-badge-mod/desoldered-components.jpg">
<img src="https://archive.org/download/dc30-biohacking-village-badge-mod/desoldered-components-640.jpg" width="640"/>
</a>


My goals for new functionality were:

- debounce the tweezers hitting the edges
- start the health meter with all LEDs lit, and remove one each hit
- flash the health meter to indicate game over, then reset to full health
- buzzer to indicate edge hits and game over
- mute switch for the buzzer

I dug a switch, buzzer, and ATtiny85 microcontroller out of my spare parts. I chose the ATtiny85 because it was small enough to fit in the available space, and had enough GPIO pins to handle 1 input from tweezers, 3 outputs for the health meter LEDs, and a pulse-width modulation output to drive the buzzer.

I prototyped the circuit on a breadboard, and banged out the [firmware code](https://github.com/nullcasa/dc30-biohacking-village-badge-mod/blob/main/src/main.c).


<iframe src="https://archive.org/embed/dc30-biohacking-village-badge-mod/breadboard.mp4" width="640" height="360" frameborder="0" webkitallowfullscreen="true" mozallowfullscreen="true" allowfullscreen></iframe>


I used a multimeter to check continuity and establish which pads the microntroller pins needed to connect to. Then I laid the switch, buzzer, and microcontroller out on the board to make sure they'd fit in the space available.


<a href="https://archive.org/download/dc30-biohacking-village-badge-mod/components-laid-out.jpg">
<img src="https://archive.org/download/dc30-biohacking-village-badge-mod/components-laid-out-640.jpg" width="640"/>
</a>


I drew up a connection diagram to follow during assembly. I was particularly happy with being able to re-use the RC debounce circuit for input current limiting and pulldown by swapping in a couple 0603 resistors that I had on hand.


<a href="https://archive.org/download/dc30-biohacking-village-badge-mod/desoldered-board.jpg">
<img src="https://archive.org/download/dc30-biohacking-village-badge-mod/desoldered-board-640.jpg" width="640"/>
</a>


Much dodgy soldering and a little gluing later, and the board now performed as desired.


<a href="https://archive.org/download/dc30-biohacking-village-badge-mod/final-soldering-1.jpg">
<img src="https://archive.org/download/dc30-biohacking-village-badge-mod/final-soldering-1-640.jpg" width="640"/>
</a>


<a href="https://archive.org/download/dc30-biohacking-village-badge-mod/final-soldering-2.jpg">
<img src="https://archive.org/download/dc30-biohacking-village-badge-mod/final-soldering-2-640.jpg" width="640"/>
</a>


A lot could be cleaner, but I was able to bang this little project out in a day, and I think the result is a fun game that lives up to the promise of this amazing badge. Thanks to [Badge Pirates](https://badgepirates.com/) and the [Biohacking Village](https://www.villageb.io/)!

<iframe src="https://archive.org/embed/dc30-biohacking-village-badge-mod/final-state.mp4" width="640" height="360" frameborder="0" webkitallowfullscreen="true" mozallowfullscreen="true" allowfullscreen></iframe>
