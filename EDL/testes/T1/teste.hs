type Time = (String, (Int, Int, Int), (Int, Int))

brasil19 :: [Time]
brasil19 = [("Corinthians", (8,7,2), (19,9)),
            ("Goias", (6,3,8), (16,27)),
            ("Flamengo", (11,3,3), (38,18)),
            ("Gremio", (5,7,5), (20,21))
            ]
            
getGols :: Time -> (Int, Int)
getGols (nome,ved,gols) = gols

-- T1.1
getNome :: Time -> String
getNome (a, (_,_,_), (_,_)) = a

nomes :: [String]
nomes = map getNome brasil19

-- T1.2
getPontuacao :: Time -> (String, Int)
getPontuacao (s, (a, b, c), (_,_)) = (s, (a * 3) + b)

pontos :: [(String, Int)]
pontos = map getPontuacao brasil19

-- T1.3
gols_positivos :: Time -> Bool
gols_positivos (_, (_,_,_), (x,y)) = x > y

positivos :: [Time]
positivos = filter gols_positivos brasil19

-- T1.4
getPts :: (Int, Int, Int) -> Int
getPts (v, e, d) = (3*v) + e

-- Primeira Forma de Fazer
g :: Int -> Time -> Bool
g n (_,ved,_) = getPts ved > n

maisN :: [Time] -> Int -> [String]
maisN times n = map getNome (filter (g n) times)

-- Segunda Forma de Fazer
-- maisN :: [Time] -> Int -> [String]
-- maisN times n = map getNome (filter g times) where
--                 g :: Time -> Bool
--                 g (_,ved,_) = getPts ved > n

-- T1.5
-- Primeira Forma de Fazer
maior :: (String, Int) -> (String, Int) -> (String, Int)
maior (a, b) (c, d) = if b >= d then (a, b) else (c, d)

campeao :: (String, Int)
campeao = foldr maior (" ", 0) pontos

-- Segunda Forma de Fazer
-- campeao :: (String, Int)
-- campeao = foldr f ("", 0) pontos where
--             f :: (String, Int) -> (String, Int) -> (String, Int)
--             f (nmN, ptN) (nmA, ptA) = if ptN >= ptA then (nmN, ptN) else (nmA, ptA)

-- T1.6
mediaGols :: [Time] -> Float
mediaGols tab = (fromIntegral totGols) / totJogos where
                totGols = foldr f 0 tab where
                            f :: Time -> Int -> Int
                            f (_,_,(gp,_)) accum = gp + accum
                            
                totJogos :: Float
                totJogos = fromIntegral (getJogs (head tab) * (length tab)) / 2.0 where
                            getJogs :: Time -> Int
                            getJogs (_,(v,e,d),_) = v + e + d

main = print(maisN brasil19 30, campeao, mediaGols brasil19)