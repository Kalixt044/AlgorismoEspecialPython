import { Image } from 'expo-image';
import { Platform, StyleSheet, TextInput, View } from 'react-native';
// CORRECCIÓN 1: Importaciones corregidas (sin .tsx y rutas correctas)
import AlertOk from '@/components/AlertOk'; // default export
import CustomButton from '@/components/CustomButton'; // default export

import { HelloWave } from '@/components/hello-wave';
import ParallaxScrollView from '@/components/parallax-scroll-view';
import { ThemedText } from '@/components/themed-text';
import { ThemedView } from '@/components/themed-view';
import { Link } from 'expo-router';

export default function HomeScreen() {
  // CORRECCIÓN 2: Agregar la función handlePress
  const handlePress = () => {
    console.log('Botón presionado');
    alert('Formulario enviado correctamente');
  };

  return (
    <ParallaxScrollView
      headerBackgroundColor={{ light: '#A1CEDC', dark: '#1D3D47' }}
      headerImage={
        <Image
          source={require('@/assets/images/MinInterior.png')}
          style={{ width: '100%', height: 200, resizeMode: 'contain' }}
        />
      }>
      <ThemedView style={styles.titleContainer}>
        <ThemedText type="title">Censo Rural!</ThemedText> 
        <HelloWave />
      </ThemedView>
      
      {/* Formulario de Nombre y Apellido */}
      <ThemedView style={styles.formContainer}>
        <ThemedText type="subtitle">Datos Personales</ThemedText>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>1Nombre:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Primer nombre"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>2Nombre:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Segundo nombre"
            placeholderTextColor="#999"
          />
        </View>

        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>1Apellido:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Primer apellido"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>2Apellido:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Segundo apellido"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Documento:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="TI/CC"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Numero de Documento:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Num. Documento"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Fecha De Nacimiento (DD/MM/AA):</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="(DD/MM/AA)"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Sexo (M/F):</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Sexo"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Numero De Telefono:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Numero de Telefono"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Direccion:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Direccion"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Barrio:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="(Barrio)"
            placeholderTextColor="#999"
          />
        </View>
        
        <View style={styles.inputContainer}>
          <ThemedText style={styles.label}>Email:</ThemedText>
          <TextInput
            style={styles.input}
            placeholder="Correo Electronico"
            placeholderTextColor="#999"
          />
        </View>
        
        {/* CORRECCIÓN 3: Botón con sintaxis correcta */}
        <View style={styles.buttonContainer}>
          <CustomButton 
            title="Enviar Formulario" 
            onPress={handlePress} 
            variant="primary"
          />
        </View>
        
      </ThemedView>
     
      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Step 1: Diligenciar formulario en minucuslas</ThemedText>
        <ThemedText>
           <ThemedText type="defaultSemiBold">Verificar los nombres y apellidos esten en su lugar adecuado</ThemedText> 
          <ThemedText type="defaultSemiBold">
            
          </ThemedText>
        </ThemedText>
      </ThemedView>
      
      <ThemedView style={styles.stepContainer}>
        <Link href="/modal">
          <Link.Trigger>
            <ThemedText type="subtitle">Step 2: Verificar</ThemedText>
          </Link.Trigger>
          <Link.Preview />
          <Link.Menu>
            <Link.MenuAction title="Action" icon="cube" onPress={() => alert('Action pressed')} />
            <Link.MenuAction
              title="Share"
              icon="square.and.arrow.up"
              onPress={() => alert('Share pressed')}
            />
            <Link.Menu title="More" icon="ellipsis">
              <Link.MenuAction
                title="Delete"
                icon="trash"
                destructive
                onPress={() => alert('Delete pressed')}
              />
            </Link.Menu>
          </Link.Menu>
        </Link>

        <ThemedText>
          {`verifica que no hayan simbolos en los campos diligenciados`}
        </ThemedText>
      </ThemedView>
      
      <ThemedView style={styles.stepContainer}>
        <ThemedText type="subtitle">Step 3: mantenga una sola ventana abierta al Diligenciar</ThemedText>
        <ThemedText>
          {`When you're ready, run `}
          <ThemedText type="defaultSemiBold">Diligenciar formulario en minusculas</ThemedText> to get a fresh{' '}
          <ThemedText type="defaultSemiBold">app</ThemedText> directory. This will move the current{' '}
          <ThemedText type="defaultSemiBold">app</ThemedText> to{' '}
          <ThemedText type="defaultSemiBold">app-example</ThemedText>.
        </ThemedText>
      </ThemedView>
    </ParallaxScrollView>
  );
}

const styles = StyleSheet.create({
  titleContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    gap: 8,
  },
  stepContainer: {
    gap: 8,
    marginBottom: 8,
  },
  formContainer: {
    gap: 16,
    marginBottom: 16,
    padding: 16,
    backgroundColor: '#f5f5f5',
    borderRadius: 8,
  },
  inputContainer: {
    gap: 4,
  },
  buttonContainer: {
    marginTop: 16,
    alignItems: 'center',
  },
  label: {
    fontSize: 16,
    fontWeight: '600',
  },
  input: {
    borderWidth: 1,
    borderColor: '#ddd',
    borderRadius: 4,
    padding: 12,
    fontSize: 16,
    backgroundColor: 'white',
  },
  reactLogo: {
    height: 178,
    width: 290,
    bottom: 0,
    left: 0,
    position: 'absolute',
  },
});
