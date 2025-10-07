import React from "react";
import { View, Text, ScrollView } from "react-native";
import AlertOk from "@/components/alertOk"; // Ajusta la ruta según tu estructura
import { Link } from "expo-router";

export default function AlertScreen() {
  return (
    <ScrollView className="flex-1 p-4 bg-white">
      <Text className="text-2xl font-bold mb-6">Pantalla de Alertas</Text>
      
      <View className="space-y-4">
        <AlertOk 
          type="success" 
          title="Éxito" 
          message="Esta es una alerta de éxito" 
        />
        
        <AlertOk 
          type="warning" 
          title="Advertencia" 
          message="Esta es una alerta de advertencia" 
        />
        
        <AlertOk 
          type="failure" 
          title="Error" 
          message="Esta es una alerta de error" 
        />
      </View>

      <Link href="/" className="mt-8 text-blue-500 text-center">
        ← Volver al inicio
      </Link>
    </ScrollView>
  );
}
