#first address,last address,address space calculation
import ipaddress
import math
addr=input("Enter the ip:")
#host=ipaddress.ip_address(addr)
ip=addr.split("/")
p=ip[1]
d=32-int(p)
try:
	m=math.pow(2,d)
	n=ipaddress.IPv4Network(addr)
	first,last=n[0],n[-1]
	print("ADDRESS BLOCK:",int(m))
	print("FIRST ADDRESS:",first)
	print("LAST ADDRESS:",last)
except:
	print("INVALID HOST BITS")
