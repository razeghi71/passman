TEMPLATE = subdirs
SUBDIRS = Vkeyboard Connection PasswordChecker PasswordGetter Main ApplicationRunner API DB
PasswordChecker.depends = Connection
PasswordGetter.depends = Connection Vkeyboard
API.depends = Connection ApplicationRunner DB
Main.depends = Connection ApplicationRunner API

