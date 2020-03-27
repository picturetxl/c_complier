

x=0

def gg():
	x=x+1
	return x

def main():
	return gg()+gg()

# Boilerplate
if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)



