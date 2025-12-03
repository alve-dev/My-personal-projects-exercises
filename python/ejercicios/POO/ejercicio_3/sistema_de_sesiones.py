"""
Ejercicio 3 — Sistema de usuarios y sesiones
Objetivo: composición de objetos.
Requerimiento profesional:
    • Clase User: nombre, email.
    • Clase Session: referencia a un User, token de sesión, estado (activa/inactiva).
    • Clase SessionManager:
        ◦ crea sesiones (create_session(user))
        ◦ las cierra
        ◦ obtiene una sesión por token
Expectativa profesional:
    • La sesión debe guardar al usuario como un objeto, no como string.
    • SessionManager debe tener una lista interna.
Tiempo estimado: 40-60 min
"""
from uuid import uuid4

class IdCounter(object):
    def __init__(self):
        self.current_id = 1
        
    def increment_id(self):
        current = self.current_id
        self.current_id += 1
        return current
        
        
class User:
    def __init__(self, name: str, email: str):
        self.name = name
        self.email = email
        
        if '@' not in email:
            raise ValueError("Email inválido, faltó '@'")
    

class Session:
    ACTIVE = "active"
    INACTIVE = "inactive"
    
    def __init__(self, user: User):
        self.user = user
        self.token_session = uuid4()
        self.state = self.ACTIVE
        
    def close(self):
        self.state = self.INACTIVE
        
        
class SessionManager:
    def __init__(self):
        self.id_counter = IdCounter()
        self.sessions_list = {}  # token -> id_user
        self.bd_user = {}        # id_user -> session
        
    def create_session(self, user: User):
        new_session = Session(user)
        user_id = self.id_counter.increment_id()
        
        self.sessions_list[new_session.token_session] = user_id
        self.bd_user[user_id] = new_session
        
        return new_session.token_session
    
    def verificar_token(self, token):
        if token not in self.sessions_list:
            raise KeyError("Token no existente.")
        
    def close_session(self, token):
        self.verificar_token(token)
        user_id = self.sessions_list[token]
        session = self.bd_user[user_id]
        session.close()  # Mejor que eliminarlo
    
    def get_session(self, token):
        self.verificar_token(token)
        user_id = self.sessions_list[token]
        return self.bd_user[user_id]
        
    def get_user(self, token):
        session = self.get_session(token)
        return session.user

        
    
admin = SessionManager()

user1 = User("Alejandro", "alejandro90@gmail.com")
user2 = User("Juan", "juan@72gmail.com")
user3 = User("Sofia", "sofia65@gmail.com")

token1 = admin.create_session(user1)
token2 = admin.create_session(user2)
token3 = admin.create_session(user3)

print(token1)
print(token2)
print(token3)

session1 = admin.get_session(token1)
user2 = admin.get_user(token3)

print(session1.user.name)
print(user2.name)