CC=gcc
end=-w -lm -lgsl -lgslcblas -O3

all: Fig2 FigS1_FigS2_FigS4_FigS5

Fig2: Fig2.c
	${CC} -o Fig2 Fig2.c ${end}

FigS1_FigS2_FigS4_FigS5: FigS1_FigS2_FigS4_FigS5.c
	${CC} -o FigS1_FigS2_FigS4_FigS5 FigS1_FigS2_FigS4_FigS5.c ${end}

