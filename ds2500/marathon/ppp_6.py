#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 26 11:09:45 2024

@author: tjkalapatapu
"""
import pandas as pd
def compute_centroids(df, k):
    centroids = []
    for cluster_id in range(k):
        cluster_df = df[df["cluster"] == cluster_id]
        mean_x = cluster_df["x"].mean()
        mean_y = cluster_df["y"].mean()
        centroids.append((mean_x, mean_y))
    return centroids