#! python3

def numDivisors(tri):
    factor = 2
    power_of_primes = []
    power_of_prime = 0

    while tri > 1:
        while tri % factor == 0:
            tri//=factor
            power_of_prime+=1
        if power_of_prime != 0:
            power_of_primes.append(power_of_prime)
        power_of_prime = 0
        factor+=1

    divisorCount = 1
    for i in power_of_primes:
        divisorCount*=(i+1)
    return divisorCount - 1

n = 1
while numDivisors( (n * (n + 1 ) ) // 2)  < 500:
    n+=1
print( (n * (n + 1) ) // 2 )