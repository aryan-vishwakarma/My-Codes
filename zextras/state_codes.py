f=open(r"C:\Users\Aryan Vishwakarma\Documents\diff\state_code.txt",'r')
content=f.readlines()
state_codes={}
for item in content:
    state,s_code=item.split('-')
    state_codes[s_code.strip()]=state.strip()
cod=input("Enter vehicle number: ")
st_co=cod[:2]
if(st_co in state_codes.keys()):
    print(state_codes[st_co])
else:
    print("This is not a valid state code")
