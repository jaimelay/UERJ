data Arvore = Folha Int | Galho Arvore Arvore
    deriving Show

a1 = Galho (Galho (Folha 15) (Folha 15)) (Galho (Folha 30) (Folha 30))
a2 = Galho (Galho (Galho (Folha 25) (Folha 25)) (Folha 40)) (Folha 35)
a3 = Galho (Folha 35) (Galho (Galho (Folha 55) (Folha 45)) (Galho (Folha 35) (Folha 35)))

soma :: Arvore -> Int
soma (Folha x) = x
soma (Galho a1 a2) = soma a1 + soma a2

dobra :: Arvore -> Arvore
dobra (Folha x) = (Folha (2*x))
dobra (Galho a1 a2) = Galho (dobra a1) (dobra a2)

possui :: Arvore -> Int -> Bool
possui (Folha x) val = (x == val)
possui (Galho a1 a2) val = (possui a1 val) || (possui a2 val)

maximo :: Arvore -> Int
maximo (Folha x) = x
maximo (Galho a1 a2) = max (maximo a1) (maximo a2)

insere :: Arvore -> Int -> Arvore
insere (Folha x) val = if (val > x) then (Galho (Folha x) (Folha val)) else (Galho (Folha val) (Folha x))
insere (Galho a1 a2) val = (Galho (insere a1 val) (insere a2 val))

-- main = print(soma a1, soma a2, soma a3)
-- main = print(dobra a1, dobra a2, dobra a3)
-- main = print(possui a1 40, possui a2 50, possui a3 55)
-- main = print(maximo a1, maximo a2, maximo a3)
main = print(insere a1 16)