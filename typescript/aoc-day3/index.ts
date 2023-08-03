
const findMatchingItemTypeOfCompartments = (rucksacks: string) => {
  const rucksacksArray = rucksacks.split("\n")
  
  const rucksackCompartments = new Map<number, string | null>()
  for (let [index, value] of rucksacksArray.entries()) {
    const rucksackLength = value.length

    const firstCompartmentEndIndex = (rucksackLength / 2) - 1
    const secondCompartmentEndIndex = rucksackLength - 1

    const firstCompartmentValues = createNewArrayBasedOnIndex(firstCompartmentEndIndex, value)
    const matchItemFound = matchItem(secondCompartmentEndIndex, value, firstCompartmentValues)

    rucksackCompartments.set(index, matchItemFound)
  }
}

const createNewArrayBasedOnIndex = (endIndex: number, rucksackCompartmentValues: string): string[] => {
  const compartmentValues: string[] = []
  for (const char of rucksackCompartmentValues) {
    compartmentValues.push(char)
  }

  return compartmentValues
}

const matchItem = (endIndex: number, rucksackCompartmentValues: string, compartmentToBeCompared: string[]): string | null => {
  for (const char of rucksackCompartmentValues) {
    if (compartmentToBeCompared.includes(char)) {
      return char
    }
  }

  return null
}

const itemTypeValues = () => {
  
} 