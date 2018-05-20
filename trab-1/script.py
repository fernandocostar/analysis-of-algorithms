import os

for i in range(1, 11):
	os.system("./busca < entradas/"+str(i)+".txt > saidas/"+str(i)+".txt")