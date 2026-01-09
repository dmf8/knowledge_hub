import argparse

parser = argparse.ArgumentParser(description="test parser")

parser.add_argument("name1", help="n1", nargs=2)
parser.add_argument("name2", help="n2", nargs='?', default='123')
parser.add_argument("-f1", "--flag1", nargs='?', const='456', default='789')
parser.add_argument("-f2", "--flag*", nargs='*')
parser.add_argument("-f3", "--flag+", nargs='+')
parser.add_argument("-f4", "--flag=2", nargs=2, default=[1, 2])

args = parser.parse_args()
# args, unknown = parser.parse_known_args()

args_dict = vars(args)
print("------------")
for k, v in args_dict.items():
    print(f"{k}: {v}")

print(args.flag1)
print(args.name2)
