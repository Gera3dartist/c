def seq_gen():
	start = 0
	while True:
		yield 2**start
		start+= 1

def relatives_calculator(last_years=None, gen=8):
	if last_years is not None:
		gen = last_years // 25
	genpow2 = seq_gen()
	amount = 0
	for item in range(gen):
		amount += next(genpow2)
	print(f'During {gen} generation(s) {amount} of people needed to cooperate for you to appear')
		

relatives_calculator(last_years=1000000)


