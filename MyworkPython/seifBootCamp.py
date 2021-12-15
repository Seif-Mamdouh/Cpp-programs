def add(number1, number2):
    return number1 + number2

def subtract(number4, number3):
    return number4 - number3

def multiplication(bitch5, bitch6):
    return bitch5 * bitch6


def division(number8, number2):
    if number2 == 0:
        return "Undefined"    
    return number8 / number2

def exponent(num1, num2):
    return num1 ** num2    


def operation(num1, operation, num2):
    if operation == "+":
        return add(num1,num2)
    
    elif operation == "-":
        return subtract(num1, num2)
    
    elif operation == "*":
        return multiplication(num1, num2)
    
    elif operation == "/":
        return division(num1, num2)
    
    elif operation == "^":
        return exponent(num1, num2)
    return




print(operation(2, "+", 3))
print(operation(2, "-", 1))
print(operation(2, "*", 2))
print(operation(8, "/", 2))
print(operation(2, "/", 0))
print(operation(2, "^", 3))





    





