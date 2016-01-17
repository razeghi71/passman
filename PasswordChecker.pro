TEMPLATE = subdirs
SUBDIRS = Vkeyboard Connection PasswordChecker PasswordGetter Main ApplicationRunner DB APIListener APIMessageViewer
PasswordChecker.depends = Connection
PasswordGetter.depends = Connection Vkeyboard
APIListener.depends = Connection ApplicationRunner DB
APIMessageViewer.depends = Connection Vkeyboard
Main.depends = Connection ApplicationRunner
