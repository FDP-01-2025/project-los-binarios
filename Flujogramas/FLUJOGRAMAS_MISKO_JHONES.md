# MISKO JHONES: Flowchart Documentation

This document describes the order and structure of all flowcharts created for the C++ game **"Misko Jhones: The Missing OL KOI"**. Each flowchart was carefully designed to represent the behavior of individual game modules and their interactions. All diagrams were uploaded as image files, and one final main flowchart was added to show the complete narrative flow.

---

## 🔁 How to Read the Flowcharts

Each flowchart corresponds to a `.h` file or a game level/function. To understand the game’s progression:

1. **Start with `menu.h`**: This file represents the entry point and main menu of the game.
2. Then follow the order defined in the `historia()` function, which dictates the story progression.
3. Each flowchart has decisions and actions shown with classic flowchart symbols:
   - **Terminator** (Oval): Start/End
   - **Process** (Rectangle): Action or instruction
   - **Decision** (Diamond): A yes/no or multi-branch decision

---

## 🧭 Order of Flowcharts (Based on `historia()` and game logic)

The images were named according to the module they represent:

1. `flujograma_menu.png` — Represents `menu.h`
2. `prologo_flujograma.png` — Represents `prologue.h`
3. `statues_flujograma.jpg` — Represents `statues.h`
4. `archery_flujograma.png` — Represents `archery.h`
5. `flujograma_casino_inicio.png` — Part 1 of `casinoGame.h`
6. `flujograma_casino_frases.png` — Part 2 of `casinoGame.h`
7. `flujograma_casino_reaccion.png` — Part 3 of `casinoGame.h`
8. `flujograma_casino_ruleta.png` — Part 4 of `casinoGame.h`
9. `chubby_flujograma.png` — Represents `chubby.h`
10. `race_flujograma.png` — Represents `race.h`
11. `softia_flujograma.jpg` — Represents `softia.h`
12. `final_battle_flujograma.png` — Represents `finalBattle.h`
13. `sleep_flujograma.png` — Represents `sleep.h` (used as a helper function in almost every module)

---

## 📌 Notes

- All diagrams were created following a vertical flow orientation for clarity.
- The `sleep.h` module was also flowcharted to show how pauses (`wait()`) are integrated.
- A **main story flowchart** was also added to visualize how levels are called from the `history()` function.

---

## 🗂️ Additional File

- `flujo.txt`: Used temporarily for textual flow annotations during development.

---

Enjoy exploring the logic behind **MISKO JHONES**! 🌀
