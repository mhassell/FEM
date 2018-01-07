# parsing the quadrature file from Matlab and autgenerating the code

inFile = open("tableQuadTri.txt")
outFile = open("parsedQuads.txt","w")

table = []
sizes = []
i = 0
for line in inFile:
	if line == "\n":
		if table == []:
			continue
		outFile.write("case %d : " % i)
		outFile.write("eigenForm << ")
		for lw in table:
			if lw == table[-1]:
				outFile.write("\t\t\t\t\t" + lw + ";\n")
			elif lw == table[0]:
				outFile.write(lw + ",\n")
			else:
				outFile.write("\t\t\t\t\t" + lw + ",\n")
		outFile.write("\t\t\t\t\t" + "break; \n\n")
		table = []
		i = i + 1

	else:
		table.append(line.rstrip("\n"))
