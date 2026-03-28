PROGRAM=player
MAIN=player.py
PYSOURCES := $(wildcard **/*.py) $(wildcard *.py)

all: $(PROGRAM) $(PROGRAM).zip

$(PROGRAM): $(MAIN)
	@chmod +x $(MAIN)


$(PROGRAM).zip:
	@zip $(PROGRAM) $(PYSOURCES)
