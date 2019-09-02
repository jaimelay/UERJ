bandas :: [[String]]
bandas = [ ["Gilberto Gil"],
           ["Victor","Leo"],
           ["Gonzagao"],
           ["Claudinho","Bochecha"] ]

musicas :: [(String, Int, Int)]
musicas = [ ("Aquele Abraco",       1, 100),
            ("Esperando na Janela", 1, 150),
            ("Borboletas",          2, 120),
            ("Asa Branca",          3, 120),
            ("Assum Preto",         3, 140),
            ("Vem Morena",          3, 200),
            ("Nosso Sonho",         4, 150),
            ("Quero te Encontrar",  4, 100) ]

-- 3.1
nome :: (String, Int, Int) -> String
nome (a,_,_) = a

nomes_musicas :: [String]
nomes_musicas = map nome musicas

-- 3.2
musicas_2min :: (String, Int, Int) -> Bool
musicas_2min (_,_,x) = x >= 120

filtra_musicas_2min :: [(String, Int, Int)]
filtra_musicas_2min = filter musicas_2min musicas

-- 3.3
maior :: Int -> Int -> Int
maior x y = if x >= y then x else y

pega_duracao :: (String, Int, Int) -> Int
pega_duracao (_,_,x) = x

duracoes :: [Int]
duracoes = map pega_duracao musicas

maior_duracao :: Int
maior_duracao = foldr maior 0 duracoes

-- 3.4
pega_nome :: (String, Int, Int) -> String
pega_nome (x,_,_) = x

nomes_musicas_2min :: [String]
nomes_musicas_2min = map pega_nome filtra_musicas_2min

-- 3.5

main = print(nomes_musicas, filtra_musicas_2min, maior_duracao, nomes_musicas_2min)