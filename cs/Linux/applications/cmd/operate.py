import argparse
import re
from pathlib import Path


def checkContent(cmd: str):
    last_line = ""
    surfix = ""
    with open("cmd.md", "r") as f:
        lines = f.readlines()
        pattern = "\|"+cmd
        for l in lines:
            last_line = l
            if re.match(pattern, l) != None:
                print(f"command '{cmd}' already exists")
                return
    if re.match(".*?\n", last_line) == None:
        surfix = "\n"
    with open("cmd.md", "+a") as f:
        f.write(surfix)
        f.write(f"|[{cmd}](details/{cmd}.md)|\n")
        print(f"command '{cmd}' added")


def checkFile(cmd: str):
    fileName = "details/"+cmd+".md"
    if Path(fileName).exists():
        print(f"file '{fileName}' already exists")
    else:
        Path(fileName).touch()
        print(f"file '{fileName}' added")


parser = argparse.ArgumentParser()

parser.add_argument("-a", "--add", help="add a command")

args = parser.parse_args()

if args.add != "":
    checkContent(args.add)
    checkFile(args.add)
