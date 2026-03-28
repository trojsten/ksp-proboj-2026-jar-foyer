# Šablóna C++

Šablóna pre `C++` pozostáva z adresára `common`, ktorý obsahuje štruktúry
objektov nachádzajúcich sa v hre, pomocné funkcie a implementáciu komunikácie so
serverom. Zo súborov v tomto priečinku sa oplatí pozrieť na `data.h`,
`helper.cpp` a `constants.h`, ostatné súbory sú pre vás zbytočné. Do priečinka
`glaze` sa radšej ani nepozerajte.

Základ vášho bota sa nachádza v súbore `bot.cpp`. Vašou úlohou je implementovať
funkcie `Bot::init` (ktorá sa spustí raz na začiatku hry) a `Bot::get_turn`
(ktorá sa spustí raz za ťah).

Svojho bota skompilujete spustením príkazu `make` v adresári bota. Tým sa
vytvorí spustiteľný súbor `player`, ktorý môžete spustiť na serveri. Tento
príkaz tiež vytvorí súbor `player.zip`, ktorý môžete nahrať na stránku.
