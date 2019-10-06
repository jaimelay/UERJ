data Arvore a = Folha | Galho a (Arvore a) (Arvore a)
    deriving Show

a1 = Galho 1 (Galho 5 Folha Folha) (Galho 6 Folha Folha)
a2 = Galho 2 (Galho 5 (Galho 7 Folha Folha) Folha) Folha
a3 = Galho 2 Folha (Galho 12 (Galho 6 Folha Folha) (Galho 8 Folha Folha))

folhas :: Arvore a -> Int
folhas Folha = 1
folhas (Galho _ a1 a2) = folhas a1 + folhas a2

altura :: Arvore a -> Int
altura Folha = 0
altura (Galho _ a1 a2) = 1 + max (altura a1) (altura a2)

espelho :: Arvore a -> Arvore a
espelho Folha = Folha
espelho (Galho x a1 a2) = (Galho x (espelho a2) (espelho a1))

soma :: Num a => Arvore a -> a
soma Folha = 0
soma (Galho x a1 a2) = x + (soma a1) + (soma a2)

dobra :: Num a => Arvore a -> Arvore a
dobra Folha = Folha
dobra (Galho x a1 a2) = (Galho (2*x) (dobra a1) (dobra a2))

possui :: Ord a => Arvore a -> a -> Bool
possui Folha y = False
possui (Galho x a1 a2) y = if (x == y) then True else (possui a1 y || possui a2 y)

possui2 :: Ord a => Arvore a -> a -> Bool
possui2 Folha y = False
possui2 (Galho x a1 a2) y = if (x == y) then True else (if (x < y) then (possui a1 y) else (possui a2 y))

maximo :: (Ord a, Num a) => Arvore a -> a
maximo Folha = 0
maximo (Galho x a1 a2) = max x (max (maximo a1) (maximo a2))

insere :: (Ord a, Num a) => Arvore a -> a -> Arvore a
insere Folha v = (Galho v Folha Folha)
insere (Galho x a1 a2) v = if (v < x) then (Galho x (insere a1 v) a2) else (Galho x a1 (insere a2 v))

-- MAP
mapA :: (a -> b) -> Arvore a -> Arvore b
mapA f Folha = Folha
mapA f (Galho x a1 a2) = (Galho (f x) (mapA f a1) (mapA f a2))

triplica :: Int -> Int
triplica x = 3*x

-- FOLDR
foldA :: (a -> b -> b) -> b -> Arvore a -> b
foldA f acc Folha = acc
foldA f acc (Galho x a1 a2) = f x (foldA f (foldA f acc a2) a1)

multiplica :: Int -> Int -> Int
multiplica x y = x * y

main = print(foldA multiplica 1 a2)