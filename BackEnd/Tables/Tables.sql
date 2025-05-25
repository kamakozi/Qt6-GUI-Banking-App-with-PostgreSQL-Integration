

CREATE TABLE IF NOT EXISTS countries(
   id SERIAL PRIMARY KEY,
   name TEXT NOT NULL
);
INSERT INTO countries (name) VALUES ('slovenia'),('germany'),('usa'),('france'),('austria'),('spain'),('united kingdom'),('italy')
ON CONFLICT DO NOTHING;

CREATE TABLE IF NOT EXISTS roles (
   id SERIAL PRIMARY KEY,
   name VARCHAR(50) UNIQUE NOT NULL
    );


INSERT INTO roles (name)
VALUES ('user'), ('admin')
    ON CONFLICT DO NOTHING;

CREATE TABLE IF NOT EXISTS users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(20) UNIQUE NOT NULL,
    email VARCHAR(50) UNIQUE NOT NULL,
    password_hash TEXT NOT NULL,
    balance NUMERIC(12,2) DEFAULT 0 CHECK (balance >= 0),
    iban TEXT UNIQUE NOT NULL,
    country_id INTEGER NOT NULL REFERENCES countries(id),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    role_id INTEGER REFERENCES roles(id) ON DELETE SET NULL
    );


CREATE TABLE IF NOT EXISTS transactions (
    id SERIAL PRIMARY KEY,
    user_id INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
    type VARCHAR(20) NOT NULL CHECK (type IN ('deposit', 'withdraw')),
    amount NUMERIC(12,2) NOT NULL CHECK (amount >= 0),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    );

CREATE TABLE IF NOT EXISTS transfer (
    id SERIAL PRIMARY KEY,
    sender_id INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
    receiver_id INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
    amount NUMERIC(12,2) NOT NULL CHECK (amount >= 0),
    description TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    );

