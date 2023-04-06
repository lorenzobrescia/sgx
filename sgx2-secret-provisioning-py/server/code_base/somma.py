f1 = open("/input/1.txt", "r")
f2 = open("/input/2.txt", "r")
f3 = open("/output/ris.txt", "w")

primo = float(f1.read())
secondo = float(f2.read())
f3.write(str(primo + secondo))
