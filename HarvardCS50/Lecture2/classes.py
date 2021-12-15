#class Point:
    #def __init__(self, x, y):
        #self.x = x
        #self.y = y 

#p = Point(3,5)
#print(p.x)
#print(p.y)



class Flight:
    def __init__(self, capacity):
        self.capacity = capacity
        self.passengers = []

    def add_passenger(self, name):
        if not self.open_seats:
            return False
        self.passengers.append(name)
        return True


    def open_seats(self):
        return self.capacity - len(self.passengers)

flight = Flight(3)

people = ["Seif", "Hoor", "Ali", "Valeria", "Aaron"]
for person in people:
    suceess = flight.add_passenger(person)
    if suceess:
        print(f"Added {person} in the flight sucessfully.")

    else:
        print(f"No availabe seats for {person} in this flight")

