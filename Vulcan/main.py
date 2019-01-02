pins = {
  # good appliances
  1: 2,
  2: 3,
  4: 4,
  8: 5,
  16: 6,
  # bad appliances
  32: 10,
  64: 11,
  128: 12,
  256: 13,
  512: 14
}

appliances = {
    2: "Good Fridge",
    3: "Good TV",
    4: "Good Dishwasher",
    5: "Good Washing Machine",
    6: "Good Water Heater",
    10: "Bad Fridge",
    11: "Bad TV",
    12: "Bad Dishwasher",
    13: "Bad Washing Machine",
    14: "Bad Water Heater"
}

electricityPrice = {
  "00:00": 2,
  "00:30": 1.5,
  '0100': -1.11,
  "0130": -1.11,
  "0200": -1.43,
  "0230": -1.43,
  "0300": 1.69,
  "0330": 2.53,
  "0400": 5

}

def subsetsum(array,num):
    if num == 0 or num < 1:
        return None
    elif len(array) == 0:
        return None
    else:
        if array[0] == num:
            return [array[0]]
        else:
            with_v = subsetsum(array[1:], (num - array[0]))
            if with_v:
                return [array[0]] + with_v
            else:
                return subsetsum(array[1:],num)

def main():
    for time, price in electricityPrice.items():
        print("Time {} with Price {}".format(time, price))
    compositeNumbers = subsetsum(list(pins.keys()), 429)
    if compositeNumbers is not None:
        for pin in compositeNumbers:
            print("Turning On Pin {} which corresponds to {}".format(pins[pin], appliances[pins[pin]]))

if __name__ == '__main__':
    main()
