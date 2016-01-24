TEMPLATE = subdirs
SUBDIRS = Vkeyboard \
          Connection \
          Encryption \
          PasswordChecker \
          PasswordGetter \
          ApplicationRunner \
          DB \
          APIMessageViewer \
          APIListener \
          Main

PasswordChecker.depends = Connection

PasswordGetter.depends = Connection \
                         Vkeyboard


APIMessageViewer.depends = Connection \
                           Vkeyboard

APIListener.depends = Connection \
                      ApplicationRunner \
                      DB \
                      Encryption


Main.depends = Connection \
               DB \
               Encryption \
               ApplicationRunner \
               APIListener

