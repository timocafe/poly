#!/usr/bin/Rscript

f <- file('stdin')
open(f)

d <- read.csv(file=f,strip.white=TRUE)
d$op.type <- interaction(d$op,d$type)
d.split <- split(d,d$op.type)
d.cols <- levels(d$op.type)

p <- data.frame(ksize=d.split[[1]]$ksize)
colnames(p)[1] <- paste0('#',colnames(p)[1])

for (i in seq(along=d.cols)) { p[[d.cols[i]]] <- d.split[[i]]$count }

write.table(p,file='',row.names=FALSE,quote=FALSE)


