#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const unsigned short NUMBER_OF_QUESTIONS = 50;
const unsigned short NUMBER_TO_ASK = 5;


// I know we're supposed to use arrays instead of pointers, but this allows me to make better use of memory.
struct _question {
	char *question;
	char *opt1;
	char *opt2;
	char *opt3;
	char *opt4;
	unsigned char correct;
};

int readAllQuestions(struct _question**);
void parseInput(char*, struct _question*); 
void displayAQuestion(struct _question**, unsigned char);
void updateTheScore(unsigned char*, unsigned char, unsigned char);
int contains(unsigned int*, unsigned int, unsigned int);

int main()
{
	// Create an array of pointers to _question objects
	struct _question *qBank[NUMBER_OF_QUESTIONS];
	unsigned char* inputBuffer = (unsigned char*)malloc(sizeof(char) * 10);
	unsigned char score = 0;
	unsigned char userResponse = 0;
	unsigned int alreadyAsked[NUMBER_TO_ASK] = {0};
	unsigned int nextQuestion;

	srand(time(NULL));
	readAllQuestions(qBank);

	for (int i = 0; i < NUMBER_TO_ASK; ++i) {
		nextQuestion = (rand() % NUMBER_OF_QUESTIONS) + 1;
		while (contains(alreadyAsked, nextQuestion, NUMBER_TO_ASK)) {
			nextQuestion = (rand() % NUMBER_OF_QUESTIONS) + 1;
		}
		printf("Question %d: ", i + 1);
		displayAQuestion(qBank, nextQuestion);
		printf("Please enter the correct answer: (1/2/3/4) \n");
		scanf("%s", inputBuffer);
		userResponse = inputBuffer[0];
		updateTheScore(&score, qBank[nextQuestion]->correct, userResponse);
		alreadyAsked[i] = nextQuestion;
	}


	printf("Your score is: %d/%d \n", score, NUMBER_TO_ASK);

	return 0;
}

int readAllQuestions(struct _question **q) {
	FILE *f = fopen("questionbank.txt", "r");
	if (f == NULL)
		exit(1);
	int counter = 0;
	char *buffer = (char*)malloc(sizeof(char) * 1000);
	for (int i = 0; i < NUMBER_OF_QUESTIONS; ++i) {
		q[i] = (struct _question*)malloc(sizeof(struct _question));
	}
	while (fgets(buffer, 1000, f)) {
		q[counter]->question = (char*)malloc(sizeof(char) * (strlen(buffer)) + 1);
		strcpy(q[counter]->question, buffer);
		fgets(buffer, 1000, f);
		q[counter]->opt1 = (char*)malloc(sizeof(char) * (strlen(buffer)) + 1);
		strcpy(q[counter]->opt1, buffer);
		fgets(buffer, 1000, f);
		q[counter]->opt2 = (char*)malloc(sizeof(char) * (strlen(buffer)) + 1);
		strcpy(q[counter]->opt2, buffer);
		fgets(buffer, 1000, f);
		q[counter]->opt3 = (char*)malloc(sizeof(char) * (strlen(buffer)) + 1);
		strcpy(q[counter]->opt3, buffer);
		fgets(buffer, 1000, f);
		q[counter]->opt4 = (char*)malloc(sizeof(char) * (strlen(buffer)) + 1);
		strcpy(q[counter]->opt4, buffer);
		fgets(buffer, 1000, f);
		q[counter]->correct = buffer[0];
		counter++;
	}
	fclose(f);
	return 0;
}

void displayAQuestion(struct _question** questions, unsigned char index) {
	printf("%s\n", questions[index]->question);
	printf("%s\n", questions[index]->opt1);
	printf("%s\n", questions[index]->opt2);
	printf("%s\n", questions[index]->opt3);
	printf("%s\n", questions[index]->opt4);
}

void updateTheScore(unsigned char *score, unsigned char cAnswer, unsigned char userAnswer) {
	if (userAnswer == cAnswer) {
		printf("Correct.\n");
		++(*score);
	} else {
		printf("Incorrect. The correct answer was: %c \n", cAnswer);
	}
}

int contains(unsigned int* container, unsigned int value, unsigned int size) {
	for (unsigned int i = 0; i < size; ++i) {
		if (container[i] == value) {
			return 1;
		}
	}
	return 0;
}
