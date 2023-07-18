import { input } from "./input"

enum MyOptions {
  "rock" = "X",
  "paper" = "Y",
  "scissors" = "Z" 
}

enum ElfOptions {
  "rock" = "A",
  "paper" = "B",
  "scissors" = "C" 
}

enum OptionsPoints {
  "rock" = 1,
  "paper" = 2,
  "scissors" = 3
}

enum GameResults {
  "lost" = 0,
  "draw" = 3,
  "win" = 6
}

const findTournamentScore = (data: string) => {
  const rounds = data.split("\n")

  console.log(rounds)

  const myOptionIndex = 2
  const elfOptionIndex = 0

  let myTotalScore = 0

  for (let round of rounds) {
    const score = roundScore(round[myOptionIndex], round[elfOptionIndex])

    myTotalScore += score
  }

  return myTotalScore
}

// I know this is ugly, I will rewrite next time I promise :D
const roundScore = (myPlay: string, elfPlay: string): number => {
  if (myPlay === MyOptions.rock && elfPlay === ElfOptions.rock) {
    return OptionsPoints.rock + GameResults.draw
  }

  if (myPlay === MyOptions.rock && elfPlay === ElfOptions.paper) {
    return OptionsPoints.rock + GameResults.lost
  }

  if (myPlay === MyOptions.rock && elfPlay === ElfOptions.scissors) {
    return OptionsPoints.rock + GameResults.win
  }

  if (myPlay === MyOptions.paper && elfPlay === ElfOptions.rock) {
    return OptionsPoints.paper + GameResults.win
  }

  if (myPlay === MyOptions.paper && elfPlay === ElfOptions.paper) {
    return OptionsPoints.paper + GameResults.draw
  }

  if (myPlay === MyOptions.paper && elfPlay === ElfOptions.scissors) {
    return OptionsPoints.paper + GameResults.lost
  }

  if (myPlay === MyOptions.scissors && elfPlay === ElfOptions.rock) {
    return OptionsPoints.scissors + GameResults.lost
  }

  if (myPlay === MyOptions.scissors && elfPlay === ElfOptions.paper) {
    return OptionsPoints.scissors + GameResults.win
  }

  if (myPlay === MyOptions.scissors && elfPlay === ElfOptions.scissors) {
    return OptionsPoints.scissors + GameResults.draw
  }

  return 0
}

const myTotalScore = findTournamentScore(input)

console.log(myTotalScore)