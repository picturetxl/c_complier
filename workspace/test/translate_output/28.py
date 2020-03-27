

def f(x):
	return x+1

def g(x):
	return f(x+1)

main():
	g
	g=4
	return f(2)

# Boilerplate
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)



