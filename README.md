# ksp-proboj-2026-jar

# Čo je Proboj a ako funguje?

Proboj, skratka pre programátorský boj, je aktivita z KSP sústredení, kde hráči
(vy) programujú vlastného bota, ktorý súťaží v predom pripravenej hre. K hre je
taktiež pripravený template bota, ktorý zvláda komunikáciu so serverom a nejaké
užitočné funkcie. Taktiež obsahuje veľmi jednoduchý príklad jednoduchého bota,
ktorého môžete ďalej upravovať.

## Ciele

Zabaviť sa a vyskúšať si niečo pekné nakódiť.

A pre tých kompetetívnejších z vás: Počas hry (matchu) bude váš bot získavať body za rôzne úkony (vid. Pravidlá) počas hry.
Tieto body sa sčítavajú medzi hrami (matchmi). Kto bude mať na konci najviac bodov, vyhráva.

# Stručný opis hry

Hra sa odohráva vo svete živých, kde každý hráč ovláda vlastnú skupinu nemŕtvych
duši.

Počas hry budete rozširovať svoje vojská "konvertovaním" smrteľníkov, eliminovať
hrobky ostatných hráčov a prežiť čo najdlhšie.

Konkrétne pravidlá sa dozviete v [pravidlách](RULES.md).

# Čo sme pre vás pripravili

Tento repozitár by mal obsahovať nasledovné veci:

- `observer` - program na prehrávanie odohratých hier
- `server_linux`, `server_windows` a `server_mac` - program s logikou hry
- `runner_linux`, `runner_windows` a `runner_mac` - program na spúšťanie hier
- `players` - priečinok s šablónami botov v C++ a pythone
- `config.json` a `games.json` - konfiguračne súbory
- `maps` - priečinok s mapami

## Spustenie hry

Po vytvorení bota je čas spustiť hru. Do súboru `config.json` pridajte svojho
bota aj s cestou k jeho hlavnému súboru. Potom v `games.json` môžete vybrať mapu
a hráčov, ktorí sa zúčastnia hry.

Hru spustíte príkazom `./runner config.json games.json`. Po dokončení hry sa
vytvorí priečinok `hra`, ktorý obsahuje záznam hry, body a logy hráčov a
servera. Záznam hry potom môžete nahrať do `observera` a hru si prehrať.

## Spustenie observera

Na spustenie observera stačí spustiť command `./run_observer.py` alebo `python
./run_observer.py`. Observer sa potom sprístupní na adrese
http://localhost:8000.
