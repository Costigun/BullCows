// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
    // Prompt Player For Guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
    
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }

    else
    {
        ProcessGuess(Input);
    }

     
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("king");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Greetings, Maksim!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); // Magic number Remove!
    PrintLine(TEXT("Your lives %i"), Lives);
    PrintLine(TEXT("Type in your guess... \nand press enter to continue..."));
}
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nType in your guess and press enter to play again ..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won!")); // You win
        EndGame();
        return;

    }

    /*if (!IsIsogram) {
        PrintLine(TEXT("No repeating letters, guess again"));
    }*/


    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The Hidden Word is %i characters long"), HiddenWord.Len());
        PrintLine(TEXT("Your Lives Remaining %i"), Lives);
        return;
    }
    PrintLine(TEXT("You have lost a life"));
    --Lives;
    if (Lives <= 0) {

        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
    
    // Show player the bulls and the cows
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}