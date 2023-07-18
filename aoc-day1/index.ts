import { text } from "./input"

// That shit is ugly and slow, I will try to rewrite it
const searchElfWithMostCalories = (elvesInvetory: string) => {
  let elf = 0
  const elvesItems = elvesInvetory.split("\n")

  const elfStorage = new Map<number, number>()

  for (let item of elvesItems) {
    if (item === "") {
      elf += 1
      continue
    }

    if (elfStorage.has(elf)) {
      const storedCalories = elfStorage.get(elf)

      if (storedCalories) {
        elfStorage.set(elf, storedCalories + Number(item))
      }
    } else {
      elfStorage.set(elf, Number(item))
    }
  }

  let elfHighest = {
    position: 0,
    calories: 0,
  }

  for (let stored of elfStorage) {
    if (stored[1] > elfHighest.calories) {
      elfHighest.position = stored[0]
      elfHighest.calories = stored[1]
    }
  }

  return elfHighest
}

const elfHighest = searchElfWithMostCalories(text)

console.log(elfHighest)