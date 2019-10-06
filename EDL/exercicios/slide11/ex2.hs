data Arvore = Folha | Galho Int Arvore Arvore
    deriving Show

a1 = Galho 45 (Galho 40 Folha Folha) (Galho 55 Folha Folha)
a2 = Galho 15 (Galho 25 (Galho 35 Folha Folha) Folha) Folha
a3 = Galho 25 Folha (Galho 35 (Galho 20 Folha Folha) (Galho 55 Folha Folha))

soma :: Arvore -> Int
soma Folha = 0
soma (Galho x a1 a2) = x + soma a1 + soma a2

dobra :: Arvore -> Arvore
dobra Folha = Folha
dobra (Galho x a1 a2) = Galho (2*x) (dobra a1) (dobra a2)

possui :: Arvore -> Int -> Bool
possui Folha val = False
possui (Galho x a1 a2) val = if (x == val) then True else (possui a1 val || possui a2 val)

possui2 :: Arvore -> Int -> Bool
possui2 Folha val = False
possui2 (Galho x a1 a2) val = if (x == val) then True else (if (val < x) then (possui2 a1 val) else (possui2 a2 val))

maximo :: Arvore -> Int
maximo Folha = 0
maximo (Galho x a1 a2) = max x (max (maximo a1) (maximo a2))

insere :: Arvore -> Int -> Arvore
insere Folha val = (Galho val Folha Folha)
insere (Galho x a1 a2) val = if (val > x) then (Galho x a1 (insere a2 val)) else (Galho x (insere a1 val) a2)

-- main = print(soma a1, soma a2, soma a3)
-- main = print(dobra a1, dobra a2, dobra a3)
-- main = print(possui a1 15, possui a2 20, possui a3 30)
-- main = print(possui2 a1 40, possui2 a3 20, possui2 a3 30)
-- main = print(maximo a1, maximo a2, maximo a3)
main = print(insere a1 35)