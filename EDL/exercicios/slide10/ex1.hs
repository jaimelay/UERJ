xs :: [Int]
xs = [1,2,3,4]

-- 1.1
eh_par :: Int -> Bool
eh_par x = (mod x 2 == 0)

pares :: [Int]
pares = filter eh_par xs

-- 1.2
incs :: Int
incs = foldr (+) 0 xs

-- 1.3
duplica :: Int -> Int
duplica x = x * 2

dups :: [Int]
dups = map duplica xs

-- 1.4
acha_maior :: Int -> Int -> Int
acha_maior x y = if x >= y then x else y

maior :: Int
maior = foldr acha_maior 0 xs

-- 1.5
acha_menor :: Int -> Int -> Int
acha_menor x y = if x <= y then x else y

menor :: Int
menor = foldr acha_menor maior xs

main = print(pares, incs, dups, maior, menor)